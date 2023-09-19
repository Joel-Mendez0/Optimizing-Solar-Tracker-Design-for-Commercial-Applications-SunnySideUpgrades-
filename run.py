from flask import Flask, render_template, Response, session, jsonify

app = Flask(__name__)
app.config['SECRET_KEY'] = 'key'


@app.route('/', methods = ['GET','POST'])
@app.route('/home', methods = ['GET','POST'])
def home():
	session.clear()
	return render_template('home.html')
	
if __name__ == "__main__":
	app.run(debug=True)
