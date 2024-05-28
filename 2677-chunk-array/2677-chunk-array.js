/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function (arr, size) {
    ans = []
    let temp = size
    let i = 0
    while (i < arr.length) {
        temp = size
        temp_arr = []
        while (i < arr.length && temp--) {
            temp_arr.push(arr[i++]);
        }

        ans.push(temp_arr);
    }

    return ans;
};
