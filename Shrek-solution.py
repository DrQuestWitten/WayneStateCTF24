from PIL import Image

image = Image.open('Content/fart.png')
pixels = image.load()

pixel_sum = 0

for i in range(0, image.size[0]):
	for j in range(0, image.size[1]):
		pixel_sum += pixels[i, j][0] + pixels[i, j][1] + pixels[i, j][2]

print(pixel_sum) # 180323325
