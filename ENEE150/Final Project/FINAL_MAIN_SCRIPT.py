import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

# LED pins (G = Green = O, R = Red = X)
pin1G, pin1R = 2, 3
pin2G, pin2R = 4, 17
pin3G, pin3R = 27, 22
pin4G, pin4R = 10, 9
pin5G, pin5R = 11, 0
pin6G, pin6R = 5, 6
pin7G, pin7R = 13, 19
pin8G, pin8R = 14, 15
pin9G, pin9R = 18, 23

green_pins = [pin3G, pin2G, pin1G, pin6G, pin5G, pin4G, pin9G, pin8G, pin7G]
red_pins   = [pin3R, pin2R, pin1R, pin6R, pin5R, pin4R, pin9R, pin8R, pin7R]

# Buttons
button1 = 21
button2 = 20
button3 = 16
button4 = 12
button5 = 1
button6 = 7
button7 = 8
button8 = 25
button9 = 24
buttons = [button1, button2, button3, button4, button5, button6, button7, button8, button9]

all_led_pins = green_pins + red_pins
for pin in all_led_pins:
    GPIO.setup(pin, GPIO.OUT, initial=GPIO.HIGH)

def turn_on_led(pin):
    GPIO.output(pin, GPIO.LOW)

def Did_Button_Get_Pressed(pin):
    InputValue = GPIO.input(pin)
    if InputValue != GPIO.HIGH:
        return 1

board = [0] * 9  # 0 = empty, 1 = X (Red), 2 = O (Green)

def is_move_legal(index):
    return board[index] == 0

def setup_leds():
    all_leds = green_pins + red_pins
    for pin in all_leds:
        GPIO.setup(pin, GPIO.OUT)
        GPIO.output(pin, GPIO.HIGH)

def setup_buttons():
    for btn in buttons:
        GPIO.setup(btn, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def check_winner():
    wins = [
        [0,1,2],[3,4,5],[6,7,8],
        [0,3,6],[1,4,7],[2,5,8],
        [0,4,8],[2,4,6]
    ]
    for a,b,c in wins:
        if board[a] != 0 and board[a] == board[b] == board[c]:
            return (board[a], [a, b, c])
    return (0, None)

def winner_celebration(winner_pin_list):
    for _ in range(3):
        for pin in winner_pin_list:
            GPIO.output(pin, GPIO.LOW)
        time.sleep(0.3)
        for pin in winner_pin_list:
            GPIO.output(pin, GPIO.HIGH)
        time.sleep(0.3)
        
def light_up(index, player):
    if player == 1:
        turn_on_led(red_pins[index])
    elif player == 2:
        turn_on_led(green_pins[index])
        
def print_board():
    display = []
    for x in board:
        if x == 0:
            display.append(' ')
        elif x == 1:
            display.append('X')
        else:  # x == 2
            display.append('O')
    print(f"{display[0]} | {display[1]} | {display[2]}")
    print(f"{display[3]} | {display[4]} | {display[5]}")
    print(f"{display[6]} | {display[7]} | {display[8]}")
    print()

setup_leds()
setup_buttons()

try:
    current_player = 1

    while True:
        print_board()
        if current_player == 1:
            print("Player X's turn")
        elif current_player == 2:
            print("Player O's turn")

        move_made = False
        while not move_made:
            for i, btn in enumerate(buttons):
                if Did_Button_Get_Pressed(btn):
                    if is_move_legal(i):
                        board[i] = current_player
                        light_up(i, current_player)
                        move_made = True
                        break
                    else:
                        print("Illegal move. Try another.")
            time.sleep(0.1)

        winner, win_indices = check_winner()
        if winner:
            winner_pins = []
            print_board()
            if winner == 1:
                print("Player X wins!")
            elif winner == 2:
                print("Player O wins!")
            for i in win_indices:
                if winner == 1:
                    winner_pins.append(red_pins[i])
                elif winner == 2:
                    winner_pins.append(green_pins[i])
            winner_celebration(winner_pins)
            break

        if 0 not in board:
            print_board()
            print("It's a tie!")
            break
        if current_player == 1:
            current_player = 2
        else:
            current_player = 1

except KeyboardInterrupt:
    print("Game interrupted.")

finally:
    GPIO.cleanup()
    print("GPIO cleaned up.")