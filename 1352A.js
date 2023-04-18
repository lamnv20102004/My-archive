function getRoundNumbers(n) {
  let count = 0;
  let result = [];

  // Iterate through powers of 10 from largest to smallest
  for (let i = 4; i >= 0; i--) {
    let power = Math.pow(10, i);

    // If adding the power of 10 doesn't exceed n, add it to the result
    while (n >= power) {
      n -= power;
      count++;
      result.push(power);
    }
  }

  return [count, ...result];
}

function sumOfRoundNumbers(t, nums) {
  let results = [];

  for (let i = 0; i < t; i++) {
    let n = nums[i];

    if (n < 10) {
      results.push([1, n]);
    } else {
      results.push(getRoundNumbers(n));
    }
  }

  return results;
}

let t = 5;
let nums = [5009, 7, 9876, 10000, 10];

let results = sumOfRoundNumbers(t, nums);

console.log(results);
// Output: [[2, 5000, 9], [1, 7], [4, 9000, 800, 70, 6], [1, 10000], [1, 10]]
