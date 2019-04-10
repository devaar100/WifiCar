package aarnav100.developer.wificar;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.webkit.WebResourceRequest;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import java.net.HttpURLConnection;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    HttpURLConnection connection;
    String url = "http://192.168.225.245/?pin=";
    WebView webView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        webView = findViewById(R.id.web_view);
        View.OnClickListener ocl = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String move = null;
                switch (view.getId()){
                    case R.id.forw:
                        move = "forw";
                        break;
                    case R.id.back:
                        move = "back";
                        break;
                    case R.id.lefo:
                        move = "lefo";
                        break;
                    case R.id.lebk:
                        move = "lebk";
                        break;
                    case R.id.rifo:
                        move = "rifo";
                        break;
                    case R.id.ribk:
                        move = "ribk";
                        break;
                    case R.id.stop:
                        move = "stop";
                        break;
                }
                sendDirection(move);
            }
        };
        findViewById(R.id.forw).setOnClickListener(ocl);
        findViewById(R.id.back).setOnClickListener(ocl);
        findViewById(R.id.lebk).setOnClickListener(ocl);
        findViewById(R.id.lefo).setOnClickListener(ocl);
        findViewById(R.id.ribk).setOnClickListener(ocl);
        findViewById(R.id.rifo).setOnClickListener(ocl);
        findViewById(R.id.stop).setOnClickListener(ocl);
    }

    void sendDirection(final String move){
        webView.loadUrl(url+move);
    }
}
