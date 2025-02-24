/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return () => {
        return "Hello World"
    }
};

// use arrow function (lambda / anonymous function)

// can omit return in arrow func and just do the following:
// return () => "Hello World" 

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */