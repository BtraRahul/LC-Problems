var TimeLimitedCache = function () {
    store = {}
    timeStore = {}
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
    const existed = key in store
    if (existed) {
        clearTimeout(timeStore[key])
    }
    store[key] = value;

    timeStore[key] = setTimeout(() => {
        delete store[key]
    }, duration)

    return existed
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {

    return (key in store) ? store[key] : -1;

};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
    // return Object.keys(this.store).length;

    let count = 0;

    for (const key in store) count++

    return count

};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */