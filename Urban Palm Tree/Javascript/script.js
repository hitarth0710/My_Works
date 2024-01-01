function httpGet(url) {
    return new Promise((resolve, reject) => {
        fetch(url)
            .then(response => {
                if (response.ok) {
                    return response.json();
                } else {
                    throw new Error('HTTP error ' + response.status);
                }
            })
            .then(json => resolve(json))
            .catch(error => reject(error));
    });
}

// Usage
httpGet('https://api.github.com/users/github')
    .then(data => console.log(data))
    .catch(error => console.error('Error:', error));