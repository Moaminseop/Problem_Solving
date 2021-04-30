window.onload = function(){
  let content = document.getElementById('picture')
  let clickCheck = false;

  content.addEventListener('mouseover', function(){
      content.style.cursor = "pointer"
    if(!clickCheck){
      content.style.transform = "scale(1.2)"
      content.style.transition = "0.5s"
    }
  })

  content.addEventListener('mouseout', function(){
    if(!clickCheck){
      content.style.transform = "scale(1)"
      content.style.transition = "0.5s"
    }
  })

  content.addEventListener('click', function(e){
    clickCheck = true;
    content.style.transform = "scale(10)"
    content.style.transition = "all 1s"
  })


  content.addEventListener('transitionend', function(event){
    if(event.elapsedTime > 0.5){
      location.href = './picture.html'
    }
  })

}
