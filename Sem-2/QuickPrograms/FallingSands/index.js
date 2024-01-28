const canvas = document.getElementById('Main-Canvas');
const Board = canvas.getContext('2d');

const ScreenWidth = window.innerWidth;
const ScreenHeight = window.innerHeight;
const CellWidth = 15;
const CellHeight = 15;
const CellGap = 1;

const NewSandAffectSize = 2;
var FPS = 60;

canvas.width = ScreenWidth;
canvas.height = ScreenHeight;

Board.fillStyle = "grey";
Board.fillRect(0, 0,ScreenWidth, ScreenHeight);


function create2DArray(rows, cols) {
    var array = [];
    for (var i = 0; i < rows; i++) {
        var row = [];
        for (var j = 0; j < cols; j++) {
            row.push(0);
        }
        array.push(row);
    }
    return array;
}
var BoardGrid = create2DArray(Math.floor(ScreenHeight/(CellGap+CellHeight)),Math.floor(ScreenWidth/(CellGap + CellWidth)));


function DrawGrid(){
    var CurrRow = 0;
    BoardGrid.forEach(row => {
        var CurrCol = 0;
        row.forEach(CELL => {
            if(CELL == 0){
                Board.fillStyle = "grey";
                Board.fillRect(CurrCol,CurrRow,CellWidth + CellGap,CellHeight + CellGap);
                Board.fillStyle = "white";
                Board.fillRect(CurrCol+(CellGap/2),CurrRow + (CellGap/2),CellWidth,CellHeight);
            }else{
                Board.fillStyle = "red";
                Board.fillRect(CurrCol,CurrRow,CellWidth + CellGap,CellHeight + CellGap);
            }
            
            CurrCol += CellGap + CellWidth;
        });
        CurrRow += CellGap + CellHeight;
    });
};
DrawGrid();

function AddNewSand(event){
    var MouseXcell = Math.floor(event.clientX / (CellGap + CellWidth));
    var MouseYcell = Math.floor(event.clientY / (CellGap + CellHeight));
    for (var row = MouseYcell - NewSandAffectSize; row <= MouseYcell + NewSandAffectSize; row++) {
        for (var col = MouseXcell - NewSandAffectSize; col <= MouseXcell + NewSandAffectSize; col++) {
            if ((col - MouseXcell) ** 2 + (row - MouseYcell) ** 2 <= NewSandAffectSize ** 2) {
                if (row >= 0 && row < BoardGrid.length && col >= 0 && col < BoardGrid[0].length) {
                    BoardGrid[row][col] = 1;
                }
            }
        }
    }
    BoardGrid[MouseYcell][MouseXcell] = 1;    
}
var isMouseDown = false;
canvas.addEventListener("mousedown", function (event) {
    isMouseDown = true;
    AddNewSand(event);
});

canvas.addEventListener("mousemove", function (event) {
    if (isMouseDown) {
        AddNewSand(event);
    }
});

canvas.addEventListener("mouseup", function () {
    isMouseDown = false;
});

function Gravity(){
    for (var row = BoardGrid.length - 1; row >= 0; row--) {
        for (var col = 0; col < BoardGrid[row].length; col++) {
            if (BoardGrid[row][col] === 1){
                if (row + 1 < BoardGrid.length && BoardGrid[row + 1][col] === 0) {
                    BoardGrid[row + 1][col] = 1;
                    BoardGrid[row][col] = 0;
                } else {
                    let dir = Math.random() < 0.5 ? -1 : 1;
                    if (row + 1 < BoardGrid.length && col + dir >= 0 && col + dir < BoardGrid[row].length && BoardGrid[row + 1][col + dir] === 0) {
                        BoardGrid[row + 1][col + dir] = 1;
                        BoardGrid[row][col] = 0;
                    }
                }
            }
        }
    }
    DrawGrid();
}
var intervalId = setInterval(Gravity, 1000 /FPS);