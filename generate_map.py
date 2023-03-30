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

sizes = [10, 20, 50, 100, 200, 500, 1000]


def get_tile_info():

    return str(len(tiles)) + "\n" + "\n".join(
        [f"{tile['key']} {tile['cost']}" for tile in tiles]
    )

def generate_map(N):
    print(get_tile_info())
    print(f"{N} {N}")


for size in sizes:
    generate_map(size)
