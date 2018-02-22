/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if(numRows <= 1) {
      return s;
    }
    var res = "";
    // Top and bottom rows will not have 2nd element
    var period = 2 * numRows - 2;
    
    // O(n) time - each char is only visited once
    for (var i = 0 ; i < numRows ; i++) {
      for (var j = i ; j < s.length ; j = j + period) {
        res = res + s[j];
        var secondElement = j - i + period - i;
        if (i > 0 && i < numRows-1) {
          if (secondElement < s.length) {
            res = res + s[secondElement];
          }
        }
      }
    }
    return res;
};