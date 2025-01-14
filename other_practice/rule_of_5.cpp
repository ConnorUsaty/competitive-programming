/*
File to practice rule of 5 implementation in cpp

The rule of 3 states that if you need to implement a user-defined destructor, copy constructor, or copy assignment operator then you likely need all 3

The rule of 5 states that if you need to implement a user-defined destructor, copy constructor, copy  assignment operator, move constructor, or move assignment operator then you likely need all 5
(Same as rule of 3 plus move constructor and move assignment operator)
*/


// make the class templated so that you can make a unq_ptr of any data type
template <typename T>
class unq_ptr {
    private:
        // always do _ prefix on member values to easily keep track of them
        T* _ptr;
    
    public:
        // defaults to nullptr is nothing passed
        explicit unq_ptr(T ptr = nullptr) : _ptr(ptr) {};

        // Destructor
        ~unq_ptr(){
            delete _ptr;
        }

        // Copy Constructor -> Cannot copy a unique ptr
        unq_ptr(const unq_ptr& p)=delete;

        // Copy Assignment Operator -> Cannot copy a unique ptr
        unq_ptr& operator=(const unq_ptr& p)=delete;

        // Move Constructor
        unq_ptr(unq_ptr&& other) noexcept : _ptr(other) {
            other = nullptr;
        }

        // Move Assignment Operator
        unq_ptr& operator=(unq_ptr&& other) noexcept {
            if(this == other&) return *this;
            delete _ptr;
            _ptr = std::exchange(other, nullptr);
            return *this;
        }
};
