const celebrateBtn = document.getElementById('celebrateBtn');

celebrateBtn.addEventListener('click', () => {
    // trigger confetti
    confetti({
        particleCount: 200,
        spread: 90,
        origin: { y: 0.7 }
    });
    setTimeout(function(){
        document.getElementById('train').classList.add('hide');
        document.getElementById('intro').classList.add('hide');
        document.getElementById('gallery').classList.add('reveal');
    },4000);
    // button animation
    celebrateBtn.style.transform = 'scale(0.95)';
    setTimeout(() => {
        celebrateBtn.style.transform = 'scale(1)';
    }, 100);
});