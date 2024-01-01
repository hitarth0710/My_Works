
function removeDuplicates(array) {
    return [...new Set(array)];
}

// Usage
let arrayWithDuplicates = [1, 2, 3, 2, 1];
let arrayWithoutDuplicates = removeDuplicates(arrayWithDuplicates);
console.log(arrayWithoutDuplicates); // Outputs: [1, 2, 3]