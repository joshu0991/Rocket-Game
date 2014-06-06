
import pygame

class Rocket:
    def __init__(self, screen):
        self.rocket = pygame.image.load('Rocket.png')
        self.screen = screen
    
    def move(self, x, y, size):
        self.screen.blit(self.rocket, (x, y))
        
    def rotate(self):
        self.rocket = pygame.transform.rotate(self.rocket, 40)