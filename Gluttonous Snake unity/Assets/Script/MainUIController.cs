using UnityEngine;
using UnityEngine.UI;

public class MainUIController : MonoBehaviour
{
    private static MainUIController _instance;
    public static MainUIController Instance
    {
        get
        {
            return _instance;
        }
    }

    public bool hasBorder = true;
    public bool isPause = false;
    public int score = 0;
    public int length = 0;
    public Text msgText;
    public Text scoreText;
    public Text bestText;
    public Image pauseImage;
    public Sprite[] pauseSprites;
    public Image bgImage;
    private Color tempColor;

    void Awake()
    {
        _instance = this;
    }

    void Start()
    {
       bestText.text=" "+PlayerPrefs.GetInt("bests", 0);
    }

    public int Update()
    {
        switch (score / 100)
        {
            case 0:
            case 1:
            case 2:
	  return 1;
                break;
            case 3:
            case 4:
                msgText.text = "阶段" + 2;
	 return 2;
                break;
            case 5:
            case 6:
                msgText.text = "阶段" + 3;
               return 3; 
	break;
            case 7:
            case 8:
                msgText.text = "阶段" + 4;
	 return 4;
                break;
            
            default:
                msgText.text = "阶段"+5;
	 return 5;
                break;
        }
    }

    public void UpdateUI(int s = 5, int l = 1)
    {
        score += s;
        scoreText.text =" "+score;
        
    }

    public void Pause()
    {
        isPause = !isPause;
        if (isPause)
        {
            Time.timeScale = 0;
            pauseImage.sprite = pauseSprites[1];
        }
        else
        {
            Time.timeScale = 1;
            pauseImage.sprite = pauseSprites[0];
        }
    }

    public void Home()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene(0);
    }
}
