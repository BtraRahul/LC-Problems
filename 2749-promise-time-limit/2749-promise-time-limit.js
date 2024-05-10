/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function (fn, t) {

    // return async function (...args) {

    //     const start = performance.now();
    //     res = await fn(...args)
    //     // res = setTimeout(() => fn(...args), t)
    //     const diff = Math.floor(performance.now() - start);

    //     console.log(res)
    //     return await new Promise((resolve, reject) => {
    //         if (diff < t)
    //             resolve(res)
    //         else reject("Time Limit Exceeded")
    //     })

    // }

    //one way
    // return async function (...args) {
    //     const promises = [
    //         new Promise(resolve => resolve(fn(...args))), //performs task irrespective of time taken
    //         new Promise((resolve, reject) => setTimeout(() => reject("Time Limit Exceeded"), t)) //reject after t millisec.
    //     ]

    //     return Promise.race(promises) //returns the fastest result

    // }

    return async function (...args) {
        return new Promise((delayresolve, reject) => {
            const timeoutId = setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t);

            fn(...args)
                .then((result) => {
                    delayresolve(result);
                })
                .catch((error) => {
                    reject(error);
                });
        });
    };
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */