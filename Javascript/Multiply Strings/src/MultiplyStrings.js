/**
 * @param {string}
 *            num1
 * @param {string}
 *            num2
 * @return {string}
 */
var multiply = function(num1, num2) {
	if(num1 == '0' || num2 == '0') {
		return '0';
	}
	var result = new Array(num1.length + num2.length).fill(0);
	for (var i = num1.length - 1; i >= 0; i--) {
		for (var j = num2.length - 1; j >= 0; j--) {
			var pos1 = (num1.length - 1 - i) + (num2.length - 1 - j);
			var pos2 = (num1.length - 1 - i) + (num2.length - 1 - j) + 1
			var placeHolder = parseInt(10 * result[pos2] + result[pos1]);
			var mult = parseInt(num1[i]) * parseInt(num2[j]);
			var number = placeHolder + mult;
			result[pos1] = number % 10;
			result[pos2] = parseInt(number / 10);
		}
	}
	var back = result.length - 1;
	while (result[back] == '0') {
		back--;
	}
	var ans = "";
	for (var i = 0; i <= back; i++) {
		ans = result[i] + ans;
	}
	return ans;
};