var TimeLimitedCache = function () {
    this.store = {}
    this.timeStore = {}
};


// if (id in memo) return memo[id]
// let x = fn(...args)
// memo[id] = x
// return x
// return memo[id] = fn(...args)

// let id = JSON.stringify(args)
// id = args.join(',')
// return (id in memo) ? memo[id] : memo[id] = fn(...args)

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
    const existed = key in this.store
    if (existed) {
        clearTimeout(this.timeStore[key])
        delete this.timeStore[key]
    }

    this.store[key] = value

    this.timeStore[key] = setTimeout(() => {
        delete this.store[key]
    }, duration)


    return existed


};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
    if (key in this.store) return this.store[key]

    return -1
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
    let count = 0;
    for (const key in this.store) {
        if (this.store.hasOwnProperty(key)) {
            count++;
        }
    }
    return count;

};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */