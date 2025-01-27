import pyBaba
import pygame
import os

BLOCK_SIZE = 48
appdir = os.path.abspath(os.path.dirname(__file__))


class SpriteLoader:
    def __init__(self):
        self.icon_images = {
            pyBaba.ObjectType.ICON_BABA: "BABA",
            pyBaba.ObjectType.ICON_FLAG: "FLAG",
            pyBaba.ObjectType.ICON_WALL: "WALL",
            pyBaba.ObjectType.ICON_ROCK: "ROCK",
            pyBaba.ObjectType.ICON_TILE: "TILE",
            pyBaba.ObjectType.ICON_WATER: "WATER",
            pyBaba.ObjectType.ICON_GRASS: "GRASS",
        }

        for i in self.icon_images:
            p, _ = os.path.split(__file__)
            fp = f'{p}/sprites/icon/{self.icon_images[i]}.gif'
            self.icon_images[i] = pygame.transform.scale(pygame.image.load(
                fp), (BLOCK_SIZE, BLOCK_SIZE))

        self.text_images = {
            pyBaba.ObjectType.BABA: "BABA",
            pyBaba.ObjectType.IS: "IS",
            pyBaba.ObjectType.YOU: "YOU",
            pyBaba.ObjectType.FLAG: "FLAG",
            pyBaba.ObjectType.WIN: "WIN",
            pyBaba.ObjectType.WALL: "WALL",
            pyBaba.ObjectType.STOP: "STOP",
            pyBaba.ObjectType.ROCK: "ROCK",
            pyBaba.ObjectType.PUSH: "PUSH",
            pyBaba.ObjectType.WATER: "WATER",
            pyBaba.ObjectType.SINK: "SINK",
        }

        for i in self.text_images:
            self.text_images[i] = pygame.transform.scale(
                pygame.image.load(
                    "{}/sprites/text/{}.gif".format(appdir, self.text_images[i])
                ),
                (BLOCK_SIZE, BLOCK_SIZE),
            )
