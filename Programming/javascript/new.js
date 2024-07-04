const name = prompt("Enter your first name:");
alert(`Hello, ${name}`);

const nb = Number(prompt("Enter a number:")); // nb's type is number
alert(nb+10);

// Creating an object using object literal syntax
let person = {
    name: "John Doe",
    age: 30,
    greet: function() {
        console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
    }
};

// Accessing properties
console.log(person.name); // Output: John Doe
console.log(person['age']); // Output: 30

// Adding a new property
person.job = "Software Developer";

// Accessing the new property
console.log(person.job); // Output: Software Developer

person.name = "Hitarth Soni"
console.log(person.name)

// Calling a method
person.greet(); // Output: Hello, my name is John Doe and I am 30 years old.

