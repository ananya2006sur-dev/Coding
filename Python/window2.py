import tkinter as tk
from tkinter import messagebox

# Create window
root = tk.Tk()
root.title("Tic Tac Toe")

# Variables
current_player = "X"
buttons = []

# Function to check win
def check_winner():
    for i in range(3):
        if buttons[i][0]["text"] == buttons[i][1]["text"] == buttons[i][2]["text"] != "":
            return True
        if buttons[0][i]["text"] == buttons[1][i]["text"] == buttons[2][i]["text"] != "":
            return True
    if buttons[0][0]["text"] == buttons[1][1]["text"] == buttons[2][2]["text"] != "":
        return True
    if buttons[0][2]["text"] == buttons[1][1]["text"] == buttons[2][0]["text"] != "":
        return True
    return False

# Button click function
def on_click(r, c):
    global current_player
    if buttons[r][c]["text"] == "":
        buttons[r][c]["text"] = current_player
        buttons[r][c]["fg"] = "red" if current_player == "X" else "blue"  # Color X red, O blue
        if check_winner():
            messagebox.showinfo("Game Over", f"Player {current_player} wins!")
            root.quit()
        elif all(buttons[i][j]["text"] != "" for i in range(3) for j in range(3)):
            messagebox.showinfo("Game Over", "It's a Draw!")
            root.quit()
        current_player = "O" if current_player == "X" else "X"

# Create buttons
for i in range(3):
    row = []
    for j in range(3):
        b = tk.Button(root, text="", font=("Arial", 40), width=5, height=2,
                      command=lambda r=i, c=j: on_click(r, c))
        b.grid(row=i, column=j)
        row.append(b)
    buttons.append(row)

root.mainloop()
