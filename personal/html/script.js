addEventListener("scroll", function () {
    let header = document.getElementByClassName("header-nav-bar");
    while (this.document.body.scrollTop > 0)
    {
        header.style.top ++;
    }
})