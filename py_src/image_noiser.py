from PIL import Image
import numpy as np
import math

def PSNR(original, compressed): 
    mse = np.mean((original - compressed) ** 2) 
    if(mse == 0):  # MSE is zero means no noise is present in the signal . 
                  # Therefore PSNR have no importance. 
        return 100
    max_pixel = 255.0
    psnr = 20 * math.log10(max_pixel / math.sqrt(mse)) 
    return psnr 

img = Image.open('../img/input/balloon.bmp')

img_arr = np.array(img)
img_arr_noise = img_arr & 254 

img_noise = Image.fromarray(img_arr_noise)
img_noise.save("../img/input/balloon_noise.bmp")

print(f"PSNR: {PSNR(img_arr, img_arr_noise)}")

