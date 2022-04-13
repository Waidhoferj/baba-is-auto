import pyBaba
import pygame
import os
appdir = os.path.abspath(os.path.dirname(__file__))

BLOCK_SIZE = 48


class SpriteLoader:
    def __init__(self):
        self.icon_images = {pyBaba.ObjectType.ICON_BABA: 'BABA',
                            pyBaba.ObjectType.ICON_FLAG: 'FLAG',
                            pyBaba.ObjectType.ICON_WALL: 'WALL',
                            pyBaba.ObjectType.ICON_ROCK: 'ROCK',
                            pyBaba.ObjectType.ICON_TILE: 'TILE'}

        for i in self.icon_images:
            self.icon_images[i] = pygame.transform.scale(pygame.image.load(
                f'{appdir}/sprites/icon/{self.icon_images[i]}.gif'), (BLOCK_SIZE, BLOCK_SIZE))

        self.text_images = {pyBaba.ObjectType.BABA: 'BABA',
                            pyBaba.ObjectType.IS: 'IS',
                            pyBaba.ObjectType.YOU: 'YOU',
                            pyBaba.ObjectType.FLAG: 'FLAG',
                            pyBaba.ObjectType.WIN: 'WIN',
                            pyBaba.ObjectType.WALL: 'WALL',
                            pyBaba.ObjectType.STOP: 'STOP',
                            pyBaba.ObjectType.ROCK: 'ROCK',
                            pyBaba.ObjectType.PUSH: 'PUSH'}

        for i in self.text_images:
            self.text_images[i] = pygame.transform.scale(pygame.image.load(
                f'{appdir}/sprites/text/{self.text_images[i]}.gif'.format()), (BLOCK_SIZE, BLOCK_SIZE))
