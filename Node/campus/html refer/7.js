#!/usr/bin/env node
//多维数组扁平化
const buff = [];

function flatten(arr) {
    var res = [];
    for (var i = 0; i < arr.length; i++) {
        if (Array.isArray(arr[i])) {
            res = res.concat(flattern(arr[i]));
        } else {
            res.push(arr[i]);
        }
    }
    return res;
}


process.stdin.on('data', (data) => {
    buff.push(data)
});

process.stdin.once('end', () => {
    const input = Buffer.concat(buff).toString('UTF-8');

    const res = flatten(JSON.parse(input));

    console.log(res);
});