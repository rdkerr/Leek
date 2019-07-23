var minWindow = function(s, t) {
  if (s.length === 0 || t.length === 0) return '';
  if (s.length < t.length) return '';
  if (s === t) {
      return s;
  }

  const map = createFrequencyTable(t);
  let counter = Object.keys(map).length;
  let start = 0;
  let answer = '';
  let end = 0;
  let min = Infinity;

  while (end < s.length) {
      if (map.hasOwnProperty(s[end])) {
          map[s[end]]--;
          if (map[s[end]] === 0){
              counter--;
          }
      }
      end++;

      while(counter ===  0) {
          if (map.hasOwnProperty(s[start])) {
              map[s[start]]++;
              if (map[s[start]] > 0){
                  counter++;
              }
          }
          if (end-start < min) {
              min = end-start;
              answer = s.substr(start, min);
          }
          start++;
      }

  }

  return answer;
};

function createFrequencyTable(s) {
  var map = {};
  for (let i = 0; i < s.length; i++) {
      if(map.hasOwnProperty(s[i])) {
          map[s[i]]++;
      } else {
          map[s[i]] = 1;
      }
  }
  return map;
}


let s = "ADOBECODEBANFCFFE";
let t = "ABC";
console.log(minWindow(s,t));

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"