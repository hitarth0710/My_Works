// Function to fetch data from an API
async function fetchData(url) {
    try {
      const response = await fetch(url);
      const data = await response.json();
      console.log(data);
    } catch (error) {
      console.error('Error:', error);
    }
  }
  
  // Call the function with a URL
  fetchData('https://jsonplaceholder.typicode.com/posts/1');