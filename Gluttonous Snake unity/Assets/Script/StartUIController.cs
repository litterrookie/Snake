using UnityEngine;
using UnityEngine.UI;

public class StartUIController : MonoBehaviour
{
    public Text lastText;
    public Text bestText;
    public Toggle blue;
    public Toggle yellow;
    public Toggle border;
    public Toggle noBorder;

    void Awake()
    {
        lastText.text =" "+PlayerPrefs.GetInt("lasts", 0);
        bestText.text=" " + PlayerPrefs.GetInt("bests", 0);
    }
    public void StartGame()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene(1);
    }
}