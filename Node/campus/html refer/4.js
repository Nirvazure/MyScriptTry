#!/usr/bin/env node
const buff = [];

function howManyDaysAreThereInFebruary(year) {
    var startDate=new Date(year,0,1),endDate=new Date(year,1,1);
    var days=(endDate-startDate)/(1000*60*60*24);
    return days;
}

process.stdin.on('data', (data) => {
    buff.push(data)
});

process.stdin.once('end', () => {
    const input = Buffer.concat(buff).toString('UTF-8');
    
    const res = howManyDaysAreThereInFebruary(input);

    console.log(res);
});