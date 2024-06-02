/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
    // let newArr = []

    // arr1.forEach(ele => {
    //     let id = ele.id


    //     let found = false

    //     newArr.forEach(newEle => {
    //         if (newEle.id == id) {
    //             newEle = ele;
    //             found = true;
    //         }
    //     })

    //     if (!found) newArr = newArr.concat(ele)
    //     console.log(ele)
    // })
    // arr2.forEach(ele => {
    //     let id = ele.id
    //     let found = false


    //     for (let i = 0; i < newArr.length; i++) {
    //         let newEle = newArr[i]
    //         if (newEle.id == id) {

    //             //we found newEle of newArr having same id as Ele in arr2
    //             //merge them
    //             for (let j = 0; j < newEle.length; j++) {
    //                 let key = newEle[j]
    //                 if (key in ele) newEle[j] = ele.key
    //                 found = true;
    //             }
    //             // newArr[i] = ele;
    //         }
    //     }

    //     if (!found) newArr = newArr.concat(ele)
    // })


    // return newArr
    arr1.sort((a,b) => a.id - b.id)
    arr2.sort((a,b) => a.id - b.id)
    const res=[]
    let i=0
    let j=0

    let n=arr1.length
    let m=arr2.length

    while(i<n || j<m){
        if(i<n && j<m && arr1[i].id === arr2[j].id){
            res.push({...arr1[i], ...arr2[j]});
            i++
            j++
        }else if(i<n && j<m && arr1[i].id < arr2[j].id || j==m){
            res.push(arr1[i++])
        }else if(i<n && j<m && arr2[j].id < arr1[i].id || i==n){
            res.push(arr2[j++])
        }
    }

    return res;
};