/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function (fn) {
    final = {}
    vis = []
    for (let i = 0; i < this.length; i++) {
        const key = fn(this[i])

        if (key in vis)
            final[key].push(this[i])
        else {
            final[key] = []
            final[key].push(this[i])
            vis[key] = 1
        }



    }

    return final;


};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */