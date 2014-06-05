import pygame, sys

pygame.init()

size = height, width = 600, 400
pygame.display.init()
screen = pygame.display.set_mode(size)
running = True
while running:
    for event in pygame.event.get():
        if(event.type == pygame.QUIT): running = False