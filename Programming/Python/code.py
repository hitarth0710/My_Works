import tkinter as tk
from tkinter import messagebox

def add_book():
    title = title_entry.get()
    author = author_entry.get()
    if title and author:
        books.append({"title": title, "author": author})
        messagebox.showinfo("Success", "Book added!")
        title_entry.delete(0, tk.END)
        author_entry.delete(0, tk.END)
    else:
        messagebox.showwarning("Error", "Please enter both title and author")

books = []

root = tk.Tk()
root.title("Book Club Buddy")

tk.Label(root, text="Title").grid(row=0)
tk.Label(root, text="Author").grid(row=1)

title_entry = tk.Entry(root)
author_entry = tk.Entry(root)

title_entry.grid(row=0, column=1)
author_entry.grid(row=1, column=1)

tk.Button(root, text="Add Book", command=add_book).grid(row=2, column=1)

root.mainloop()
