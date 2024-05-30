var currentUrl = window.location.href;
var url = new URL(currentUrl);
var params = new URLSearchParams(url.search);
var user = params.get('user');
console.log('param1:', user);
if(user == null){
    user = 1;
}else{
    user = 0;
}



const accept_btn = document.getElementById("accept");
const increaset_btn = document.getElementById("increase");
const reject_btn = document.getElementById("reject");
const L_score = document.getElementById('Lscore');
const R_score = document.getElementById('Rscore');



function sendDictionary(dictionary) {
    var url = "file.php";

    fetch(url, {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify(dictionary)
    })
    .then(response => response.json())
    .then(responseData => {
        console.log(responseData);
    })
}

function getDictionary() {
    var url = "file.php";

    fetch(url)
    .then(response => response.json())
    .then(responseData => {
        console.log(responseData);
        data = responseData;
        if(data['mode'] == 0){
            accept_btn.classList.add('hide');
            reject_btn.classList.add('hide');
            increaset_btn.classList.add('solo');
        }else{
            if((user == 0 && data['mode']==2)||(user == 1 && data['mode'] == 1)){
                accept_btn.classList.remove('hide');
                reject_btn.classList.remove('hide');
                increaset_btn.classList.add('hide');
                if(data['mode']==1){
                    L_score.style.color = 'orange';
                    L_score.innerHTML = data['L']['score'] + 1;
                }else{
                    R_score.style.color = 'orange';
                    R_score.innerHTML = data['R']['score'] + 1;
                }
            }else{
                accept_btn.classList.add('hide');
                reject_btn.classList.add('hide');
                increaset_btn.classList.add('solo');
                increaset_btn.classList.add('inactive');
            }
        }
        
        if(data['responce'] != 0){
            data['responce'] = 0;
            data['mode'] == 0;
        }
    })
}
var SCORES = {"L":{"score":0,"message":""},"R":{"score":0,"message":""},"mode":0,"responce":0};




data = getDictionary();









function Increase(){
    if(data['mode']==0){
        if(user == 0){
            data['mode'] = 1;
        }else{
            data['mode'] = 2;
        }
        data['responce'] = 0;
        sendDictionary(data);
    }else{
        increaset_btn.classList.add('inactive');
    }
}
function Accept(){
    if(user == 0){
        data['responce'] = 1;
        data['mode'] = 0;
        data['R']['score'] = data['R']['score'] + 1;
        data['']
    }
}