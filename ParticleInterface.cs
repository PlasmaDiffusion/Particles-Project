using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class ParticleInterface : MonoBehaviour
{
    public float m_Attraction;
    public int m_MaxDistance;
    public GameObject m_SpawnableObject;

    [StructLayout(LayoutKind.Sequential)]
    public struct Vec
    {
        public float x, y, z;
    }
    [StructLayout(LayoutKind.Sequential)]
    public struct Particle
    {
        public Vec Pos;
        public Vec Vel;
    }
    //entry points for our dll
    [DllImport("MyParticleSystem")]
    public static extern void initSystem();
    [DllImport("MyParticleSystem")]
    public static extern void CleanUpSystem();
    [DllImport("MyParticleSystem")]
    public static extern void initializeParticles(Particle[] p, int size, int MaxDistance);
    [DllImport("MyParticleSystem")]
    public static extern void updateSystemPosition(float x, float y, float z);
    [DllImport("MyParticleSystem")]
    public static extern void updateAttraction(float f);
    [DllImport("MyParticleSystem")]
    public static extern void updateParticles(Particle[] p, float dt);
    // Use this for initialization
    Particle[] g_Arr = new Particle[50];
    GameObject[] ParticleArr = new GameObject[50];

    void SetPosition()
    {
        for (int i = 0; i < 50; i++)
        {
            ParticleArr[i].transform.position = new Vector3(g_Arr[i].Pos.x, g_Arr[i].Pos.y, g_Arr[i].Pos.z);
        }
    }
    void Start()
    {
        for (int i = 0; i < 50; i++)
        {
            ParticleArr[i] = Instantiate<GameObject>(m_SpawnableObject);
        }
        initSystem();
        updateAttraction(m_Attraction);
        updateSystemPosition(transform.position.x, transform.position.y, transform.position.z);
        initializeParticles(g_Arr, 50, m_MaxDistance);
        SetPosition();
    }

    // Update is called once per frame
    void Update()
    {
        updateSystemPosition(transform.position.x, transform.position.y, transform.position.z);
        updateParticles(g_Arr, Time.deltaTime);
        SetPosition();
    }
}
