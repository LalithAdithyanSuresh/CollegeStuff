from flask import Flask, jsonify
import requests
import matplotlib.pyplot as plt
import io
import base64

app = Flask(__name__)

# Replace with your API key
API_KEY = "your_api_key_here"

def get_player_data(player_tag):
    headers = {
        "Authorization": f"Bearer {API_KEY}"
    }
    response = requests.get(f"https://api.clashofclans.com/v1/players/%23{player_tag}", headers=headers)
    return response.json()

def calculate_attack_percentages(player_data):
    # This is a placeholder. You'll need to parse the data to get actual attack percentages.
    return [attack['percentage'] for attack in player_data['attacks']]

@app.route('/player/<player_tag>/attack-graph')
def attack_graph(player_tag):
    player_data = get_player_data(player_tag)
    percentages = calculate_attack_percentages(player_data)

    # Create the graph
    plt.figure(figsize=(10,5))
    plt.plot(percentages)
    plt.title(f"Attack Percentages for {player_tag}")
    plt.xlabel("Attacks")
    plt.ylabel("Percentage")
    
    # Convert plot to PNG image
    img = io.BytesIO()
    plt.savefig(img, format='png')
    img.seek(0)
    img_base64 = base64.b64encode(img.getvalue()).decode('utf8')

    return f"<img src='data:image/png;base64,{img_base64}'/>"

if __name__ == '__main__':
    app.run(debug=True)