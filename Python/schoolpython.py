import tkinter as tk
from tkinter import messagebox

class TicTacToe:
    def _init_(self):
        self.window = tk.Tk()
        self.window.title("Tic Tac Toe")

        self.current_player = "X"
        self.buttons = [[None for _ in range(3)] for _ in range(3)]

        self.create_board()
        self.window.mainloop()

    def create_board(self):
        for row in range(3):
            for col in range(3):
                btn = tk.Button(self.window, text="", font=('Arial', 32), width=5, height=2,
                                command=lambda r=row, c=col: self.on_click(r, c))
                btn.grid(row=row, column=col)
                self.buttons[row][col] = btn

    def on_click(self, row, col):
        btn = self.buttons[row][col]
        if btn["text"] == "":
            btn["text"] = self.current_player
            if self.check_winner(row, col):
                messagebox.showinfo("Game Over", f"Player {self.current_player} wins!")
                self.reset_board()
            elif self.is_draw():
                messagebox.showinfo("Game Over", "It's a draw!")
                self.reset_board()
            else:
                self.current_player = "O" if self.current_player == "X" else "X"

    def check_winner(self, row, col):
        symbol = self.current_player
        # Check row
        if all(self.buttons[row][c]["text"] == symbol for c in range(3)):
            return True
        # Check column
        if all(self.buttons[r][col]["text"] == symbol for r in range(3)):
            return True
        # Check diagonals
        if row == col and all(self.buttons[i][i]["text"] == symbol for i in range(3)):
            return True
        if row + col == 2 and all(self.buttons[i][2 - i]["text"] == symbol for i in range(3)):
            return True
        return False

    def is_draw(self):
        return all(self.buttons[r][c]["text"] != "" for r in range(3) for c in range(3))

    def reset_board(self):
        for row in self.buttons:
            for btn in row:
                btn["text"] = ""
        self.current_player = "X"

# Run the game
TicTacToe()
