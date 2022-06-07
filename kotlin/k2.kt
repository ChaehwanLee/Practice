fun main(args: Array<String){
    ifExample()
    loopExample()
    caseExample()
}

fun caseExample(){
    // var obj : Any? = "aaaa";
    var obj : Any? = 10.00f
    // var obj :Any? = 8;
    when(obj){
        "aaaa" -> {println("문자:"+obj)}
        is Float -> {println("숫자:"+obj)}
        in(0 .. 9) -> {println("0-10까지 숫자")}
        else -> {println("???")}
    }
}