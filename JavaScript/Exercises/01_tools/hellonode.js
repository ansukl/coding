const _ = require("lodash");
const ver = _.VERSION;
console.log(ver);

function hithere(array) {
    last = _.last(array);
    first = _.head(array);
    val = last + " and " + first;
    return val;
    
}

module.exports = hithere;