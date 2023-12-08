import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        message = ""
        inputname = request.form.get("name")
        inputMonth = request.form.get("Month")
        inputDay = request.form.get("Day")
        inputYear = request.form.get("Year")
        if not inputname:
            message = "You didn't enter any name !"
        elif not inputDay:
            message = "Birthday is missing from your input"
        elif not inputMonth:
            message = "you didn't enter birth Month"
        elif not inputYear:
            message = "you didn't enter birth Year"
        else:
            db.exeute(
                "INSERT INTO birthdays (name, Day, Month, Year) VALUES(?, ?, ?, ?)",
                inputname,
                inputDay,
                inputMonth,
                inputYear,
            )
        birthdays = db.execute("SELECT * FROM birhdays")
        return render_template("index.html", message=message, birthday=birthday)

    else:

        # TODO: Display the entries in the database on index.html
        birthday = db.execute("SELECT * FROM birthday")
        return render_template("index.html", birthday=birthday)

