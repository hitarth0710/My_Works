class Callme
{
    void call(String msg){
        System.out.println();
    }
}


class Caller implements Runnable{
    String msg;
    Callme target;
    Thread t;

    public Caller(Callme targ, String s){
        target = targ;
        msg = s;
        t = new Thread();
        t.start();
    }

    public void run(){
    }

}




public class threadingdemo
{

}