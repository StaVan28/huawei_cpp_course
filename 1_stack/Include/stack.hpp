
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

//-----------------------------------------------------------------------------

//#define DEFENCE_STACK 

//!

#define RECREATE_DUMP_STACK_FILE                                \
        FILE* dump_stack = fopen("./Txt/dump_stack.txt", "wb"); \
        fclose(dump_stack);                                     \

//!

#define ASSERT_STACK_OK(retrn)  \
        if (error() != 0) {     \
                ERROR_INFO      \
                retrn           \
        }                       \

//!

#define ERROR_INFO                         \
        strcpy(error_info.file, __FILE__); \
        strcpy(error_info.func, __func__); \
        error_info.line = __LINE__;        \

//-----------------------------------------------------------------------------

namespace Stack
{
    static const int CHAR_MEMORY  = 25;
    static const int CAPACITY_MIN = 4;
    static const int CAPACITY_DIF = 4;
    static const int TWO_CANARIES = 2;
    static const int HAVE_ERROR   = 0;

    static const int    POISON_INT_STACK    = 0X1CD7E30B;
    static const double POISON_DOUBLE_STACK = NAN;

    static const int CANARY_LEFT_STACK  = 0X237CA57A;
    static const int CANARY_RIGHT_STACK = 0X2CD71868;
    static const int CANARY_LEFT_DATA   = 0X3425D763;
    static const int CANARY_RIGHT_DATA  = 0X37B6B0FE;

    //---------------------------------------

    struct error_stack_t 
    {
        char file[CHAR_MEMORY] = {};
        char func[CHAR_MEMORY] = {};
        int  line              = POISON_INT_STACK;
    };

    static error_stack_t error_info = {};

    //---------------------------------------

    enum Stack_errors
    {
        SUCCESS                  = 0,
        NULL_PTR_STACK           = 1,
        NEGATIVE_CURRENT_SIZE    = 2,
        NEGATIVE_CAPACITY        = 3,
        CUR_SIZE_MORE_CAPACITY   = 4,
        NULL_PTR_DATA            = 5,
        UNKNOW_NUMBER_CONSTRUCT  = 6,
        UNKNOWN_NUMBER           = 7,
        CANARY_DATA_ERROR        = 8,
        CANARY_STACK_ERROR       = 9,
        HASH_ERROR               = 10,
        REALLOC_ERROR            = 11,
        CALLOC_ERROR             = 12,
        CONSTRUCT_ERROR          = 13,
    };

    //-----------------------------------------------------

    class Stack 
    {
        private:

            int   canary_left_stack_  = 0;
            char* data_               = nullptr;
            char  name_[CHAR_MEMORY]  = {};
            int   capacity_           = 0;
            int   cur_size_           = 0;
            int   hash_               = 0;
            int   error_              = 0;
            int   canary_right_stack_ = 0;

            //---------------------------------------

            int realloc_data()
            {
                ASSERT_STACK_OK({return POISON_INT_STACK;})

                int temp_capacity = capacity_;

                if (capacity_ < CAPACITY_MIN)
                    capacity_  = CAPACITY_MIN;
                else if (cur_size_ * CAPACITY_DIF < capacity_)
                    capacity_ /= 2;
                else
                    capacity_ *= 2;

                char *temp_stck_data = data_;

                #ifdef DEFENCE_STACK
                    data_ -= sizeof(int);
                    data_  = (char*) realloc(data_, capacity_ * sizeof(double) + TWO_CANARIES * sizeof(int));
                #else
                    data_  = (char*) realloc(data_, capacity_ * sizeof(double));
                #endif

                if (data_ == nullptr) 
                {
                    data_  = temp_stck_data;

                    error_ = REALLOC_ERROR;
                    ERROR_INFO

                    return REALLOC_ERROR;
                }

                #ifdef DEFENCE_STACK
                    data_ += sizeof(int);
                #endif

                for (int indx = temp_capacity; indx < capacity_; indx++)
                    *(double*)(data_ + indx * sizeof(double)) = POISON_DOUBLE_STACK;

                #ifdef DEFENCE_STACK
                    *(int*)(data_ + capacity_ * sizeof(double)) = CANARY_RIGHT_DATA;
                    hash_ = hash();
                #endif

                ASSERT_STACK_OK({return POISON_INT_STACK;})

                return SUCCESS;
            }

            //---------------------------------------

            int hash()
            {
                int hash_ = POISON_INT_STACK;

                for (int indx = 0; indx < cur_size_; indx++) 
                {
                    hash_ = hash_ + (int)(data_[indx * sizeof(double)]);

                    if (indx % 2) 
                    {
                        hash_  |= cur_size_;
                        hash_ <<= capacity_;
                        hash_  |= *(name_);
                    }
                    else 
                    {
                        hash_  |= capacity_;
                        hash_ <<= cur_size_;
                        hash_  |= *(name_);
                    }
                }

                return hash_;
            }

            //---------------------------------------

            int error()
            {
                if (this == nullptr) {
                    return NULL_PTR_STACK;
                } 

                if (cur_size_ < 0) {
                    error_ = NEGATIVE_CURRENT_SIZE;
                    return NEGATIVE_CURRENT_SIZE;
                }

                if (capacity_ < 0) {
                    error_ = NEGATIVE_CAPACITY;
                    return NEGATIVE_CAPACITY;
                }

                if (cur_size_ > capacity_) {
                    error_ = CUR_SIZE_MORE_CAPACITY;
                    return CUR_SIZE_MORE_CAPACITY;
                }

                if (data_ == nullptr) {
                    error_ = NULL_PTR_DATA;
                    return NULL_PTR_DATA;
                }

                if (error_ != 0)
                    return HAVE_ERROR; 

                #ifdef DEFENCE_STACK
                    if (*(int*)(data_ - 1 * sizeof(int)) != CANARY_LEFT_DATA) {
                        error_ = CANARY_DATA_ERROR;
                        return CANARY_DATA_ERROR;
                    }

                    if (*(int*)(data_ + capacity_ * sizeof(double)) != CANARY_RIGHT_DATA) {
                        error_ = CANARY_DATA_ERROR;
                        return CANARY_DATA_ERROR;
                    }

                    if (canary_left_stack_ != CANARY_LEFT_STACK) {
                        error_ = CANARY_STACK_ERROR;
                        return CANARY_STACK_ERROR;
                    }

                    if (canary_right_stack_ != CANARY_RIGHT_STACK) {
                        error_ = CANARY_STACK_ERROR;
                        return CANARY_STACK_ERROR;
                    }

                    if (hash_ != hash()) {
                        error_ = HASH_ERROR;
                        return HASH_ERROR;
                    }
                #endif

                return SUCCESS;
            }

            //---------------------------------------

            const char* text_error() const
            {
                switch(error_) 
                {
                    case NEGATIVE_CURRENT_SIZE:
                        return "NEGATIVE CURRENT SIZE";
                    case NEGATIVE_CAPACITY:
                        return "NEGATIVE CAPACITY";
                    case CUR_SIZE_MORE_CAPACITY:
                        return "CURRENT SIZE MORE CAPACITY";
                    case NULL_PTR_DATA:
                        return "NULL_PTR_DATA";
                    case UNKNOW_NUMBER_CONSTRUCT:
                        return "UNKNOW NUMBER CONSTRUCT";
                    case UNKNOWN_NUMBER:
                        return "NAN in stack";
                    case CANARY_DATA_ERROR:
                        return "CANARY DATA ERROR";
                    case CANARY_STACK_ERROR:
                        return "CANARY STACK ERROR";
                    case HASH_ERROR:
                        return "HASH ERROR";
                    case REALLOC_ERROR:
                        return "REALLOC ERROR: Your push sooo big!";
                    case CALLOC_ERROR:
                        return "CALLOC_ERROR: Calloc func didn't work";
                    case CONSTRUCT_ERROR:
                        return "CONSTRUCT ERROR: You initialization stack again";
                    default:
                        return "NULL PTR STACK";
                }
            }

            //---------------------------------------

        public:

            Stack() = delete;

            //---------------------------------------

            Stack(const char* name, int capacity)
            {
                RECREATE_DUMP_STACK_FILE

                if (canary_left_stack_ != 0) 
                {
                    error_ = CONSTRUCT_ERROR;
                    ERROR_INFO
                    return;
                }

                if (capacity < 0)
                {
                    error_ = UNKNOWN_NUMBER;
                    ERROR_INFO
                    return;
                }

                #ifdef DEFENCE_STACK
                    data_ = (char*) calloc(capacity * sizeof(double) + TWO_CANARIES * sizeof(int), sizeof(char));
                #else
                    data_ = (char*) calloc(capacity * sizeof(double), sizeof(char));
                #endif

                if (data_ == nullptr) 
                {
                    error_ = CALLOC_ERROR;
                    ERROR_INFO
                    return;
                }

                #ifdef DEFENCE_STACK
                    data_ += sizeof(int);

                    *(int*)(data_ - 1 * sizeof(int))           = CANARY_LEFT_DATA;
                    *(int*)(data_ + capacity * sizeof(double)) = CANARY_RIGHT_DATA;
                #endif

                capacity_ = capacity;

                for (int indx = 0; indx < capacity_; indx++)
                    *(double*)(data_ + indx * sizeof(double)) = POISON_DOUBLE_STACK;

                strcpy(name_, name);

                #ifdef DEFENCE_STACK
                    hash_ = hash();

                    canary_left_stack_  = CANARY_LEFT_STACK;
                    canary_right_stack_ = CANARY_RIGHT_STACK;
                #endif

                ASSERT_STACK_OK({return;})
            }
            
            //---------------------------------------

        ~Stack()
        {
                ASSERT_STACK_OK({return;})

                canary_left_stack_ = POISON_INT_STACK;

                for (int indx = 0; indx < capacity_; indx++)
                    *(double*)(data_ + indx * sizeof(double)) = POISON_INT_STACK;

                capacity_ = POISON_INT_STACK;
                cur_size_ = POISON_INT_STACK;

                #ifdef DEFENCE_STACK
                    data_ -= sizeof(int);
                #endif

                free(data_);
                data_ = nullptr;

                hash_               = POISON_INT_STACK;
                canary_right_stack_ = POISON_INT_STACK;
            }
            
            //---------------------------------------

            Stack(const Stack&)              = delete;
            Stack& operator = (const Stack&) = delete;
            
            //---------------------------------------

            void push(double data)
            {
                ASSERT_STACK_OK({return;})

                if (!isfinite(data)) 
                {
                    error_ = UNKNOWN_NUMBER;
                    ERROR_INFO
                    return;
                }

                int status_realloc = SUCCESS;

                if (cur_size_ == capacity_ || capacity_ < CAPACITY_MIN)
                    status_realloc = realloc_data();

                if (status_realloc == SUCCESS) 
                {
                    *(double*)(data_ + cur_size_ * sizeof(double)) = data;
                    cur_size_++;
                }

                #ifdef DEFENCE_STACK
                    hash_ = hash();
                #endif

                ASSERT_STACK_OK({return;})
            }
            
            //---------------------------------------

            double pop()
            {
                ASSERT_STACK_OK({return POISON_DOUBLE_STACK;})

                int status_realloc = SUCCESS;

                if (capacity_ > CAPACITY_MIN && cur_size_ * CAPACITY_DIF < capacity_)
                    status_realloc = realloc_data();

                double temp_data = 0;

                if (status_realloc == SUCCESS) 
                {
                    cur_size_--;
                    temp_data = *(double*)(data_ + cur_size_ * sizeof(double));
                    
                    if (cur_size_ >= 0)
                        *(double*)(data_ + cur_size_ * sizeof(double)) = POISON_DOUBLE_STACK;
                }

                #ifdef DEFENCE_STACK
                    hash_ = hash();
                #endif

                ASSERT_STACK_OK({return POISON_DOUBLE_STACK;})

                return temp_data;
            }

            //---------------------------------------

            void dump() const
            {
                FILE* dump_stack = fopen("./Txt/dump_stack.txt", "ab");
                assert(dump_stack);

                fprintf(dump_stack, "\n******************************************************\n");
                fprintf(dump_stack, "       Stack:\n\n");

                if (!error_)
                    fprintf(dump_stack, "Stack (OK) [%p] \"%s\" {\n\n", this, name_);
                else 
                {
                    fprintf(dump_stack, "Stack (ERROR %d : %s) [%p] \"%s\" {\n", error_, text_error(), this, name_);
                    fprintf(dump_stack, "In File : %s, LINE : %d\n", error_info.file, error_info.line);
                    fprintf(dump_stack, "In Function : %s\n\n",    error_info.func);

                    printf(             "Stack (ERROR %d : %s) [%p] \"%s\" {\n", error_, text_error(), this, name_);
                    printf(             "In File : %s, LINE : %d\n", error_info.file, error_info.line);
                    printf(             "In Function : %s\n\n",    error_info.func);
                }

                #ifdef DEFENCE_STACK
                    fprintf(dump_stack, "Canary left  = %d  [%p]\n", canary_left_stack_, &(canary_left_stack_));
                #endif

                fprintf(dump_stack, "Current size = %d\n", cur_size_);
                fprintf(dump_stack, "Capacity     = %d\n", capacity_);

                #ifdef DEFENCE_STACK
                    fprintf(dump_stack, "Hash         = %d\n", hash_);
                    fprintf(dump_stack, "Canary right = %d  [%p]\n", canary_right_stack_, &(canary_right_stack_));
                #endif

                fprintf(dump_stack, "\nData [%p]\n", data_);

                if (capacity_ != POISON_INT_STACK) 
                {
                    #ifdef DEFENCE_STACK
                        fprintf(dump_stack, " {canary_left} : %d  [%p]\n\n", *(int*)(data_ - 1 * sizeof(int)), \
                                                                              (int*)(data_ - 1 * sizeof(int)));
                    #endif

                    int indx = 0;
                    for ( ; indx < cur_size_; indx++)
                        fprintf(dump_stack, "*{%2d} : %lg\n", indx + 1, *(double*)(data_ + indx * sizeof(double)));
                    for ( ; indx < capacity_; indx++)
                        fprintf(dump_stack, " {%2d} : %lg (POISON)\n", indx + 1, *(double*)(data_ + indx * sizeof(double)));

                    #ifdef DEFENCE_STACK
                        fprintf(dump_stack, "\n {canary_right} : %d  [%p]\n", *(int*)(data_ + capacity_ * sizeof(double)), \
                                                                            (int*)(data_ + capacity_ * sizeof(double)));
                    #endif
                }

                fprintf(dump_stack, "}\n");
                fprintf(dump_stack, "\n******************************************************\n");

                fclose(dump_stack);
            }

            //---------------------------------------
    };

}

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------

#endif // STACK_H_INCLUDED
