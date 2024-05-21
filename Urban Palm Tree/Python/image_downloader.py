import requests

def download_image(url, filename):
    response = requests.get(url, stream=True)
    if response.status_code == 200:
        with open(filename, 'wb') as file:
            for chunk in response.iter_content(1024):
                file.write(chunk)
    else:
        print(f"Unable to download image. HTTP response code: {response.status_code}")

# Usage
url = "https://images.freeimages.com/images/large-previews/53d/leather-link-texture-1538412.jpg?fmt=webp&h=350"  # replace with your image url
filename = "downloaded_image.jpg"  # replace with your desired file name
download_image(url, filename)
