$(document).ready(function() {
    var inicio = document.getElementById('link-inicio'),
        sobre = document.getElementById('link-sobre'),
        liInicio = document.getElementById('li-inicio'),
        liSobre = document.getElementById('li-sobre');

    $(inicio).click(function() {
        $(sobre).removeClass("text-active");
        $(sobre).addClass("nav-l");
        $(liSobre).removeClass("ul-li-active");
        $(inicio).addClass("text-active");
        $(inicio).removeClass("nav-l");
        $(liInicio).addClass("ul-li-active");
    });

    $(sobre).click(function() {
        $(inicio).removeClass("text-active");
        $(inicio).addClass("nav-l");
        $(liInicio).removeClass("ul-li-active");
        $(sobre).addClass("text-active");
        $(sobre).removeClass("nav-l");
        $(liSobre).addClass("ul-li-active");
    });
});