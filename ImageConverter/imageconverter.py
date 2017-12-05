from PIL import Image
import sys
import os


def convert_image(path):
    image = Image.open(path)
    if image.size[0] != 8 or image.size[1] != 8:
        print('Invalid size:' + image.size)
        return

    image_data = image.getdata(3)
    out_data = []
    for x in range(8):
        value = 0
        for y in range(8):
            value >>= 1
            pixel = image_data[x + y * 8]
            if pixel > 128:
                value |= 0x80
        out_data.append(value)
    print('const uint8_t ' + os.path.splitext(os.path.basename(path))
          [0] + '[] PROGMEM = {' + ', '.join([hex(x) for x in out_data]) + '};')


if __name__ == '__main__':
    convert_image(sys.argv[1])
