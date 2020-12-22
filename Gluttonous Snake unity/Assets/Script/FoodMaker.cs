using UnityEngine;
using UnityEngine.UI;

public class FoodMaker : MonoBehaviour
{
    private static FoodMaker _instance;
    public static FoodMaker Instance
    {
        get
        {
            return _instance;
        }
    }

    public int xlimit = 10;
    public int ylimit = 11;
    
    public GameObject foodPrefab;
    public GameObject rewardPrefab;
    public Sprite[] foodSprites;
    private Transform foodHolder;

    void Awake()
    {
        _instance = this;
    }

    void Start()
    {
        foodHolder = GameObject.Find("FoodHolder").transform;
        MakeFood(0);
    }

    public void MakeFood(int type)
    {
	if(type==0){
        int index = Random.Range(0, foodSprites.Length);
        GameObject food = Instantiate(foodPrefab);
        food.GetComponent<Image>().sprite = foodSprites[index];
        food.transform.SetParent(foodHolder, false);
        int x = Random.Range(-xlimit, xlimit);
        int y = Random.Range(-ylimit, ylimit);
        food.transform.localPosition = new Vector3(x * 15, y * 15, 0);}
        if (type==1)
        {
            GameObject reward = Instantiate(rewardPrefab);
            reward.transform.SetParent(foodHolder, false);
            int x = Random.Range(-xlimit, xlimit);
            int y = Random.Range(-ylimit, ylimit);
            reward.transform.localPosition = new Vector3(x * 15, y * 15, 0);
        }
    }
}