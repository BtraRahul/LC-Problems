/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    return new Promise((resolve, reject) => {
        const ans = new Array(functions.length)
        // ans = []
        let count = 0
        functions.forEach((fn, i) => {
            fn()
                .then(val => {
                    ans[i] = (val);
                    count++;
                    if (count === functions.length) {
                        resolve(ans);
                    }
                })
                .catch(reason => { reject(reason) })
        })

    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */