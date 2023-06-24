/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let i=0;
    return function() {
        
        let v=n+i;
        i++;
        return v;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */