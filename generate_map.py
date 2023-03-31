from random import randint
import sys

tiles = [
    {
        'key': 'f',
        'cost': 3
    },
    {
        'key': 'g',
        'cost': 1
    },
    {
        'key': 'G',
        'cost': 2
    },
    {
        'key': 'h',
        'cost': 4
    },
    {
        'key': 'm',
        'cost': 7
    },
    {
        'key': 'r',
        'cost': 5
    }
]


def get_tile_info():
    return str(len(tiles)) + "\n" + "\n".join(
        [f"{tile['key']} {tile['cost']}" for tile in tiles]
    )


def generate_map(N):
    map_info = get_tile_info() + f"\n{N} {N}\n"
    output_string = map_info
    for i in range(N):
        for j in range(N):
            if j != 0:
                output_string += ' '

            tile = tiles[randint(0, len(tiles) - 1)]
            output_string += tile['key']
        output_string += '\n'
    output_string += f"0 0\n{N-1} {N-1}"
    print(output_string)


if (len(sys.argv) != 2):
    sys.exit()

size = sys.argv[1]
if not size.isdigit():
    sys.exit()

generate_map(int(size))
