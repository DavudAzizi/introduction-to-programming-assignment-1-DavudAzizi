from flask import Flask, render_template_string, request, redirect, session, url_for
from werkzeug.security import generate_password_hash, check_password_hash

app = Flask(__name__)
app.secret_key = "dev-secret-change-me"

USERS = {}
PRODUCTS = [
    {"id": 1, "name": "Notebook", "price": 2.50},
    {"id": 2, "name": "Pen", "price": 1.00},
    {"id": 3, "name": "Backpack", "price": 25.00},
]

BASE = """
<!doctype html>
<title>{{ title }}</title>
<h1>{{ title }}</h1>
<nav>
  <a href="/">Home</a> |
  <a href="/register">Register</a> |
  <a href="/login">Login</a> |
  <a href="/store">Store</a> |
  <a href="/cart">Cart</a> |
  <a href="/logout">Logout</a>
</nav>
<hr>
{{ body|safe }}
"""

@app.route("/")
def index():
    name = session.get("user", "Guest")
    return render_template_string(BASE, title="Week 10 Flask App", body=f"<p>Hello, {name}!</p>")

@app.route("/hello")
def hello():
    name = request.args.get("name", "world")
    return render_template_string(BASE, title="Hello", body=f"<p>Hello, {name}!</p>")

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username", "").strip()
        password = request.form.get("password", "")
        if not username or not password:
            return render_template_string(BASE, title="Register", body="<p>Missing username or password.</p>")
        USERS[username] = generate_password_hash(password)
        return redirect(url_for("login"))
    body = """
    <form method="post">
      <input name="username" placeholder="Username">
      <input name="password" type="password" placeholder="Password">
      <button>Register</button>
    </form>
    """
    return render_template_string(BASE, title="Register", body=body)

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form.get("username", "").strip()
        password = request.form.get("password", "")
        if username in USERS and check_password_hash(USERS[username], password):
            session["user"] = username
            return redirect(url_for("index"))
        return render_template_string(BASE, title="Login", body="<p>Invalid login.</p>")
    body = """
    <form method="post">
      <input name="username" placeholder="Username">
      <input name="password" type="password" placeholder="Password">
      <button>Login</button>
    </form>
    """
    return render_template_string(BASE, title="Login", body=body)

@app.route("/store")
def store():
    items = "".join(
        f"<li>{p['name']} - ${p['price']:.2f} <a href='/add/{p['id']}'>Add</a></li>"
        for p in PRODUCTS
    )
    return render_template_string(BASE, title="Store", body=f"<ul>{items}</ul>")

@app.route("/add/<int:product_id>")
def add(product_id):
    cart = session.get("cart", [])
    cart.append(product_id)
    session["cart"] = cart
    return redirect(url_for("cart"))

@app.route("/cart")
def cart():
    ids = session.get("cart", [])
    selected = [p for p in PRODUCTS if p["id"] in ids]
    total = sum(p["price"] for p in selected)
    rows = "".join(f"<li>{p['name']} - ${p['price']:.2f}</li>" for p in selected)
    return render_template_string(BASE, title="Cart", body=f"<ul>{rows}</ul><p>Total: ${total:.2f}</p>")

@app.route("/logout")
def logout():
    session.clear()
    return redirect(url_for("index"))

if __name__ == "__main__":
    app.run(debug=True)
