
<!doctype html>
<html lang="pt-BR">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Feliz Aniversário ❤️</title>
  <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@300;600;800&family=Great+Vibes&display=swap" rel="stylesheet">
  <style>
    :root{
      --bg1:#4b1d63; /* roxo profundo */
      --bg2:#a54edb; /* lilás/roxo claro */
      --accent:#ffffff;
      --card:#ffffff1a;
      --glass: rgba(255,255,255,0.08);
    }
    *{box-sizing:border-box}
    html,body{height:100%;margin:0;font-family:Montserrat,system-ui,Arial,Helvetica,sans-serif;color:var(--accent);background:linear-gradient(135deg,var(--bg1) 0%, #5f1c80 40%, var(--bg2) 100%);-webkit-font-smoothing:antialiased}

    .wrap{min-height:100vh;display:flex;align-items:center;justify-content:center;padding:32px}
    .card{width:100%;max-width:980px;background:linear-gradient(180deg, rgba(255,255,255,0.03), rgba(255,255,255,0.02));border-radius:20px;padding:26px;box-shadow:0 10px 30px rgba(2,6,23,0.6);position:relative;overflow:hidden;border:1px solid rgba(255,255,255,0.06)}

    /* left photo */
    .grid{display:grid;grid-template-columns:380px 1fr;gap:24px;align-items:center}
    .photo{height:420px;border-radius:16px;overflow:hidden;position:relative;background:linear-gradient(135deg,#2e0f3a,#4b1d63);display:flex;align-items:center;justify-content:center}
    .photo img{width:100%;height:100%;object-fit:cover;display:block}

    /* overlay play heart */
    .heart{position:absolute;left:18px;bottom:18px;background:linear-gradient(90deg,#ff7ab6,#ffb86b);padding:10px;border-radius:999px;display:flex;gap:10px;align-items:center;backdrop-filter:blur(6px);box-shadow:0 6px 18px rgba(0,0,0,0.35)}
    .heart b{font-weight:700}

    /* content */
    .content{padding:18px}
    .title{font-family:'Great Vibes',cursive;font-size:48px;margin:0 0 6px;line-height:0.95}
    .subtitle{margin:0 0 18px;font-weight:600;opacity:0.95}

    .message{background:var(--card);padding:18px;border-radius:12px;color:var(--accent);min-height:160px}
    .message [contenteditable]{outline:none;border:none;background:transparent;color:inherit;font-size:16px}

    .controls{display:flex;gap:12px;align-items:center;margin-top:14px}
    .btn{background:transparent;border:1px solid rgba(255,255,255,0.12);padding:10px 14px;border-radius:10px;cursor:pointer;font-weight:700}

    /* floating hearts animation */
    .floaters{position:absolute;inset:0;pointer-events:none}
    .floater{position:absolute;opacity:0.85;animation:floatUp linear infinite}
    @keyframes floatUp{from{transform:translateY(20vh) scale(0.6);opacity:0} to{transform:translateY(-30vh) scale(1);opacity:1}}

    /* confetti */
    #confetti{position:absolute;inset:0;pointer-events:none}

    /* responsive */
    @media(max-width:880px){
      .grid{grid-template-columns:1fr;}
      .photo{height:280px}
      .title{font-size:36px}
    }

    /* small helpers */
    .small{font-size:13px;opacity:0.9}
  </style>
</head>
<body>
  <audio src="URL-DA-SUA-MUSICA.mp3" autoplay loop style="display:none;"></audio>
  <div class="wrap">
    <div class="card">

      <div class="floaters" id="floaters"></div>
      <canvas id="confetti"></canvas>

      <div class="grid">
        <div class="photo" id="photoBox">
          
          <img id="mainPhoto" src="https://i.postimg.cc/Xjf0P13L/foto-namorada.jpg" alt="Nossa foto" onerror="this.style.filter='grayscale(30%)';this.alt='Adicione sua foto: substitua photo.jpg'">
          <div class="heart">
            <svg width="22" height="22" viewBox="0 0 24 24" fill="none" aria-hidden><path d="M12 21s-7.5-4.35-10-7.02C-0.7 9.92 3.33 5 7.5 7.5 9 8.6 10 10.8 12 13c2-2.2 3-4.4 4.5-5.5C20.67 5 24.7 9.92 22 13.98 19.5 17.65 12 21 12 21z" fill="#fff" opacity="0.95"/></svg>
            <b>É hoje!</b>
          </div>
        </div>

        <div class="content">
          <h1 class="title" id="title" contenteditable="true">Feliz Aniversário, amor</h1>
          <div class="subtitle small" contenteditable="true">Hoje é seu dia — e eu te celebro com tudo o que sou.</div>

          <div class="message">
            <div contenteditable="true" id="messageText">
              Meu amor,
              <br><br>
              Cada dia com você é um presente. Hoje eu quero que saiba o quanto você ilumina minha vida — seus risos, seu jeito, seu olhar. Obrigado por ser minha parceira, minha amiga e meu abrigo. Que esse ano te traga tudo o que seu coração deseja.
              <br><br>
              Com todo meu carinho,
              <br>
              <strong>— Seu nome</strong>
            </div>
          </div>

          <div class="controls">
            
            <button class="btn" id="stopConfetti">Parar confete</button>
            <a class="btn" id="downloadBtn" href="#" download="homenagem-aniversario.html">Salvar HTML</a>
          </div>

          <div style="margin-top:12px;font-size:13px;opacity:0.0"></div>
        </div>
      </div>

    </div>
  </div>

  <!-- hidden but present iframe (positioned behind photo) -->
  

  <script>
    // --- YouTube hidden player control (autoplay attempted; may be blocked by browser policies) ---
    

    // floating hearts generator
    const floaters = document.getElementById('floaters');
    const colors = ['#ff7ab6','#ffd166','#7af7e6','#ffb86b'];
    function spawnHeart(){
      const el = document.createElement('div');
      el.className='floater';
      const size = Math.random()*32+22;
      el.style.width = size+'px';
      el.style.height = size+'px';
      el.style.left = (Math.random()*92)+'%';
      el.style.bottom = '-10%';
      el.style.opacity = Math.random()*0.7 + 0.3;
      el.style.animationDuration = (5+Math.random()*6)+'s';
      el.style.background = 'none';
      el.innerHTML = `
        <svg width="${size}" height="${size}" viewBox="0 0 24 24" fill="${colors[Math.floor(Math.random()*colors.length)]}" opacity="0.9">
          <path d="M12 21s-7.5-4.35-10-7.02C-0.7 9.92 3.33 5 7.5 7.5 9 8.6 10 10.8 12 13c2-2.2 3-4.4 4.5-5.5C20.67 5 24.7 9.92 22 13.98 19.5 17.65 12 21 12 21z"/>
        </svg>`;
      floaters.appendChild(el);
      setTimeout(()=>el.remove(),15000);
    }
    setInterval(spawnHeart,400);

    // confetti canvas
    const canvas = document.getElementById('confetti');
    const ctx = canvas.getContext('2d');
    let W, H, confetti = [];
    function resize(){ W = canvas.width = window.innerWidth; H = canvas.height = window.innerHeight; }
    window.addEventListener('resize', resize); resize();

    function rand(min,max){ return Math.random()*(max-min)+min }
    function makeConfetti(){
      confetti = [];
      for(let i=0;i<120;i++){
        confetti.push({x:rand(0,W),y:rand(-H,0),r:rand(6,12),d:rand(1,3),w:rand(6,12),c:colors[Math.floor(Math.random()*colors.length)],rot:rand(0,360),spd:rand(1,3)});
      }
    }
    makeConfetti();
    let confOn = true;
    function draw(){
      ctx.clearRect(0,0,W,H);
      if(confOn){
        for(let p of confetti){
          ctx.save();
          ctx.translate(p.x,p.y); ctx.rotate(p.rot*Math.PI/180);
          ctx.fillStyle = p.c; ctx.fillRect(-p.w/2,-p.r/2,p.w,p.r);
          ctx.restore();
          p.x += Math.sin(p.d)+p.spd*0.5; p.y += p.spd;
          p.rot += 2;
          if(p.y>H+20){ p.y = rand(-100,0); p.x = rand(0,W); }
        }
      }
      requestAnimationFrame(draw);
    }
    draw();
    document.getElementById('stopConfetti').addEventListener('click', ()=>{ confOn = !confOn; document.getElementById('stopConfetti').textContent = confOn ? 'Parar confete' : 'Ligar confete'; });

    // download current HTML (simple snapshot)
    document.getElementById('downloadBtn').addEventListener('click', (e)=>{
      e.preventDefault();
      const blob = new Blob([document.documentElement.outerHTML], {type:'text/html'});
      const url = URL.createObjectURL(blob);
      const a = document.createElement('a'); a.href=url; a.download='homenagem-aniversario.html'; a.click(); URL.revokeObjectURL(url);
    });

    // double click photo to replace via file picker
    const photo = document.getElementById('mainPhoto');
    photo.addEventListener('dblclick', ()=>{
      const inp = document.createElement('input'); inp.type='file'; inp.accept='image/*';
      inp.onchange = e => {
        const file = e.target.files[0]; if(!file) return;
        const url = URL.createObjectURL(file); photo.src = url; photo.alt = file.name;
      };
      inp.click();
    });

  </script>
</body>
</html>
c
