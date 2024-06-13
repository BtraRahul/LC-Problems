/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function (nums) {
    // var sum = 0;
    // var str = ""
    // this.nusval = [...nums]
    // // console.log(val)

    // val.forEach(e => sum += e);
    // const s = JSON.stringify(this.val)

    this.nums = nums;
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function (other) {
    return this.nums.reduce((acc, cur) => acc + cur, 0);
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function () {
    return JSON.stringify(this.nums)
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */