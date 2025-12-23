import tkinter as tk
from tkinter import messagebox

# Initialize window
root = tk.Tk()
root.title("Tic Tac Toe")

# Current player ('X' starts)
current_player = "X"

# Board state (3x3)
board = [[None for _ in range(3)] for _ in range(3)]

# Function to check for a win
def check_winner():
    # Check rows
    for row in board:
        if row[0] == row[1] == row[2] and row[0] is not None:
            return True

    # Check columns
    for col in range(3):
        if board[0][col] == board[1][col] == board[2][col] and board[0][col] is not None:
            return True

    # Check diagonals
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] is not None:
        return True
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] is not None:
        return True

    return False

# Function to check for a tie
def check_tie():
    for row in board:
        if None in row:
            return False
    return True

# Function to handle button click
def on_click(r, c):
    global current_player

    if buttons[r][c]["text"] == "" and board[r][c] is None:
        buttons[r][c]["text"] = current_player
        board[r][c] = current_player

        if check_winner():
            messagebox.showinfo("Game Over", f"Player {current_player} wins!")
            root.quit()
        elif check_tie():
            messagebox.showinfo("Game Over", "It's a tie!")
            root.quit()
        else:
            current_player = "O" if current_player == "X" else "X"

# Create buttons
grid_frame = tk.Frame(root)
grid_frame.pack()

buttons = [[None for _ in range(3)] for _ in range(3)]

for r in range(3):
    for c in range(3):
        buttons[r][c] = tk.Button(grid_frame, text="", font=('normal', 40), width=5, height=2,
                                  command=lambda r=r, c=c: on_click(r, c))
        buttons[r][c].grid(row=r, column=c)

# Start the game loop
root.mainloop()

